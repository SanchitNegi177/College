# tup1=(1,2,3)
# tup2=(4,5,6)
# tup3=(7,8,9)
# tup4=tup1,tup2,tup3
# print(tup4)
# print(tup4[2])

# tuple are immutable so ERROR
# tup1=(1,2,3)
# tup1[0]=2
# print(tup1)

# x=int(input('enter\n'))
# print (x)
# x=eval(input('enter x\n'))
# y=(input('enter y\n'))
# print (type(x))
# print (type(y))

# a=5
# b=a
# c=b
# d=2+3
# print (id(a))
# print (id(b))
# print (id(c))
# print (id(d))

# tup1=(1,2,3)
# tup2=(4,5,6)
# tup3=(7,8,9)
# tup4=tup1+tup2+tup3
# print(tup4)                 (1, 2, 3, 4, 5, 6, 7, 8, 9)
# tup4=tup1,tup2,tup3
# print(tup4)                 ((1, 2, 3), (4, 5, 6), (7, 8, 9))



l1=[1,2,3]
l2=[4,5,6]
l3=[7,8,9]

# print(l1)              [1, 2, 3]
# l1=[l1+[2,34,5]]
# print(l1)              [[1, 2, 3, 2, 34, 5]]

# print(l1)                 [1, 2, 3]
# l1.append([2,34,5])
# print(l1)                 [1, 2, 3, [2, 34, 5]]

# print(l1)                   [1, 2, 3]
# l1.extend([2,34,5]) 
# print(l1)                   [1, 2, 3, 2, 34, 5]

# l4=[]
# l4.append(l1)
# l4.append(l2)
# l4.append(l3)
# l4[2][1]=[0,0,0]
# print(l4)                   #[[1, 2, 3], [4, 5, 6], [0, 0, 0]]

# data={1:'hi',2:"hello",6:"hhh"}
# print (data.get(3,"UNAVAILABLE"))  #UNAVAILABLE
# data[1]=5                     #change data
# data[3]='python'               #add new data
# print(data)                     #{1: 5, 2: 'hello', 6: 'hhh', 3: 'python'}


# l1=[1,2,3]
# l2=[4,5,6]
# dic=dict(zip(l1,l2))
# print(dic)

# set1={1,2,3,4,3}
# set2={1,2,5,6,7,8}
# set3=set1|set2                  #{1, 2, 3, 4, 5, 6, 7, 8} intersection
# set4=set1&set2                  #{1, 2} union

# set3=set1 or set2               #{1, 2, 3, 4}
# set4=set1 and set2              #{1, 2, 5, 6, 7, 8}

# set1.add("k")
# set1.remove("k")
# print(set1)

# name="sanchit negi is a betech student"
# l=[]
# temp=''
# for i in range(len(name)):
#     if(name[i]==' '):
#         l.append(temp)
#         temp=''
#     else:
#         temp+=name[i]
# l.append(temp)

# for i in range(len(l)):
#     l[i][0].title()
  

# print(l)



name="sanchit negi is a betech student"
newname=''
l=[]
temp=''
for i in range(len(name)):           # string to list and uppercase of every word
    if(name[i]==' '):
        l.append(temp)
        temp=''
    elif(name[i-1]==' 'or i==0):
        temp+=name[i].upper()
    else:
        temp+=name[i]
l.append(temp)                                 # to get last word

for i in range(len(l)):                        #data from list to string
    newname+=l[i]
    newname+=' '

print(newname)