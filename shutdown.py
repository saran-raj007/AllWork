import os
c=input("shutdown your laptop? (y or n)")
if c=='y' or  c=='Y':
    os.system("shutdown /s")
else:
    print("bye")
