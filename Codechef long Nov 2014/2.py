#!/usr/bin/python

import sys
import re
import os
import shutil


def solve():
  line=input();
  n=len(line);
  cont=[];
  for i in range(0,30):
    cont.append(False);
    
  for i in range (0,n):
    cont[ ord(line[i]) - 97 ] = True;

  mx=0;

  for i in range (0,30):
    if( cont[i]  == True  ):
      mx = mx + 1;

  print(mx);    
  return;

def main():
  test= int( input() );
  while(test > 0):
    solve();
    test=test-1;
  return;  
  
if __name__ == "__main__":
  main()
