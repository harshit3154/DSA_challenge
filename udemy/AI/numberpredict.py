import random
list=[]
list2=[]

for x in range(101):
    list.append(x)

p=dict()
for x in range(100):
    r=random.choice(list)


print()

for x in range(101):
    print(random.choice(list),end=" ")
