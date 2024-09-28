import argparse

parser = argparse.ArgumentParser(description="script to test search algorithms runtimes")
    
parser.add_argument("-b", "--binary", action="store_const", const="b", dest="id", help="activate binary search")
parser.add_argument("-l", "--linear", action="store_const", const="l", dest="id", help="activate linear search")
   
args = parser.parse_args()

if args.id is None:
    parser.print_help()
    print("\nError: Choose a valid flag to continue.")
    exit()

if args.id == "b":
    print("Binary Search: ")
elif args.id == "l":
    print("Linear Search: ")

