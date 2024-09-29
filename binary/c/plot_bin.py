import matplotlib.pyplot as plt
import numpy as np

nx = 648
nz = 1150

path = "data/model_vp_2d.bin"

model = np.fromfile(path, dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")

model_from_txt = np.loadtxt("data/model_vp_2d.txt") # you can add .reshape([nx,nz], order="F")

height, width = model_from_txt.shape

model_from_txt = model_from_txt.reshape([width, height], order="F")

plt.imshow(model_from_txt)

plt.show()

