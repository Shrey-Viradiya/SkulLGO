import random
with open('data.csv','w') as f, open("search.csv", 'w') as f2:
    f.write("key,value\n")
    for _ in range(100):
        key = random.randint(0,1000000)
        f.write(f"{key},{random.randint(1000,5000)}\n")
        if(random.randint(0,10) == 9):
            f2.write(f"{key},")
        