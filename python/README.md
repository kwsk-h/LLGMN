# LLGMN Python

## ***Log-Linearized Gaussian Mixture Network***

`mini-batch learning`

## Development environment
- Python 3.9.7
- Numpy 1.20.3


# Using LLGMN

```python
  import pandas as pd
  data=np.array(pd.read_csv('data/data.csv', header=None).dropna(axis=1))
  label=np.array(pd.read_csv('data/label.csv', header=None).dropna(axis=1))
  data_test=np.array(pd.read_csv('data/data_test.csv', header=None).dropna(axis=1))
  label_test=np.array(pd.read_csv('data/label_test.csv', header=None).dropna(axis=1))

  ll = LLGMN()
  ll.setWeight()
  Y_train = ll.train(data, label)
  Y_test = ll.test(data_test, label_test)
```
