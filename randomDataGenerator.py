import random
with open('data.csv','w') as f:
    f.write("key,value\n")
    for _ in range(100):
        f.write(f"{random.randint(0,1000)},{random.randint(1000,5000)}\n")