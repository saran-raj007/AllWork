def Choice_list():
    
    print("Choice_list:\n1.ADD\n2.UPDATE\n3.DELETE")
def update_po(x,v):
    for i in range(0,len(a)):
        if (i+1)==x:
            a[i]=v

def update_val(x,y):
    for i in range(0,len(a)):
        if a[i]==x:
            a[i]=y
            

def Del(x):
    
            a.remove(x)
f=1 
print("Enter your list of values: ")
global a
a=list(map(int,input().split()))
while f==1:
    print(Choice_list())
    print("ENter your option: ")
    n=int(input())
    if n==1:
        print("Enter Which element you want to add: ")
        s=int(input())
        a.append(s)
        print("successfully updated\n")
        print(a)
    elif n==2:
        print("position wise update or element wise update: ")
        print("1.Position\n2.element\n")
        g=int(input())
        if g==1:
            print("Enter the position: ")
            f=int(input())
            print("enter which you wnat to update: ")
            v=int(input())
            update_po(f,v)
            print("successfully updated")
            print(a)
        else:
            print("Enter which element you want to update: ")
            p=int(input())
            print("Enter the new value: ")
            k=int(input())
            update_val(p,k)
            print("successfully updated\n")
            print(a)
    elif n==3:
        print("Enter which value you want to delete: ")
        t=int(input())
        Del(t)
        print("successfully Deleted\n")
        print(a)
    print("Do you want to continue(1/0):")
    l=int(input())
    f=l

    