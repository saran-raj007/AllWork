import os
c=input("are you want to shutdown your laptop? (y or n)")
if c=='y' or  c=='Y':
    os.system("shutdown /s")
else:
    print("thanku for using")
