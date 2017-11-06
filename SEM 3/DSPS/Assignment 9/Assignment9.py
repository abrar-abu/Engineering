# -*- coding: utf-8 -*-
# @Author: ubuntu
# @Date:   2017-11-06 12:49:55
# @Last Modified 2017-11-06
# @Last Modified time: 2017-11-06 12:50:54
print"     ----------Bubble Sort Using Python----------\n"

arr=[]
num=0
temp=0
tot=0

print"\nEnter the number of elements to be sorted: ",
tot=input()

for i in range(0,tot):
  print"\nEnter",i+1,"Element: ",
  num=input()
  arr.append(num)

for i in range(1,tot):
  for j in range(0,(tot-i)):
    if(arr[j]>arr[j+1]):
      temp=arr[j]
      arr[j]=arr[j+1]
      arr[j+1]=temp
     
print"\nSorted Elements are:\n"
for i in range (0,tot):
  print"\n",arr[i],
  
print"\n",	