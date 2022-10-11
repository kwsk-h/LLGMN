# -*- coding: utf-8 -*-
import numpy as np


class LLGMN:

    def __init__(self):
        self.D = 2
        self.H = int(1 + self.D * (self.D + 3) / 2)
        self.K = 4
        self.M = 2
        self.epsilon = 0.1
        self.batch_size = 400
        self.max_epoch = 500
        self.data = []
        self.weight = []
        self.IO = {}

    def setWeight(self):
        self.weight = np.random.rand(self.K, self.M, self.H)

    def inputConversion(self, input_data):
        conv_data = [1]
        conv_data.extend(input_data)
        tmp = [input_data[i]*input_data[j] for i in range(self.D) for j in range(i, self.D)]
        conv_data.extend(tmp)
        return np.array(conv_data)

    def forward(self, batch_data):
        I1 = np.array([self.inputConversion(x) for x in batch_data])
        O1 = I1
        I2 = np.array([np.sum(o1 * self.weight, axis=2) for o1 in O1])
        O2 = np.array([np.exp(i2) / np.sum(np.exp(i2)) for i2 in I2])
        I3 = np.sum(O2, axis=2)
        O3 = I3

        self.IO = {'I1':I1, 'O1':O1, 'I2':I2, 'O2':O2, 'I3':I3, 'O3':O3}

        return O3


    def backward(self, batch_T):
        grad = [((self.IO['O3'][i] - batch_T[i]).reshape(self.K, 1)
                 * (self.IO['O2'][i] / self.IO['O3'][i].reshape(self.K, 1))).reshape(self.K, self.M, 1)
                 * self.IO['I1'][i] for i in range(self.batch_size)]
        self.grad = np.sum(grad, axis=0) / self.batch_size
        self.weight -= self.epsilon * self.grad

    def train(self, data, label):
        for epoch in range(self.max_epoch):
            iter_per_epoch = max(int(len(data)/self.batch_size), 1)
            for i in range(iter_per_epoch):
                idx = np.random.choice(len(data), size=self.batch_size, replace=False)
                _ = self.forward(data[idx])
                self.backward(label[idx])
            Y = self.forward(data)
            loss = np.sum((Y-label)**2)
            entropy = np.sum(-1*label*np.log(Y))/len(data)
            acc = sum(np.argmax(t) == np.argmax(y) for t, y in zip(label, Y))/len(data)
            print(epoch, ':', acc, loss, entropy)
        return Y

    def test(self, data, label):
        Y = self.forward(data)
        acc = sum(np.argmax(t) == np.argmax(y) for t, y in zip(label, Y))/len(data)
        print('Accurcy : ', acc)
        return Y

####################################
if __name__ == "__main__":
    import pandas as pd
    data=np.array(pd.read_csv('data/data.csv', header=None).dropna(axis=1))
    label=np.array(pd.read_csv('data/label.csv', header=None).dropna(axis=1))
    data_test=np.array(pd.read_csv('data/data_test.csv', header=None).dropna(axis=1))
    label_test=np.array(pd.read_csv('data/label_test.csv', header=None).dropna(axis=1))

    ll = LLGMN()
    ll.setWeight()
    Y_train = ll.train(data, label)
    Y_test = ll.test(data_test, label_test)
