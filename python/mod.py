import numpy as np

def test_scalar(x):
  return int(2*x)

def test_numpy(x):
  a = x * np.ones(5, dtype=np.double)
  return a
