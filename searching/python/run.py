import numpy as np
import time
from src import Search, p

def run(id: str):
    arr = np.random.randint(100_000_000, size=100_000_000) 
    arr.sort()
    num = arr[15_335_300] 

    s = Search(arr, num)

    idx = getattr(s, f"idx_{id}", "Choose a valid id!")

    print(f"num is in arr[{idx}]")

if __name__ == '__main__':
    start = time.time()

    run(p.args.id)

    end = time.time()

    print(f"Runtime: {(end - start):.4f} seconds")

