import os
import subprocess
import platform
from pathlib import Path
import sys
from time import sleep

def main() -> None:

    print("C source files batch compiler. Compile multiple files altogether.")
    print("v1.0")

    dir_path = input("Enter source directory path: ")

    c_file_list = []

    for files in os.walk(dir_path):
        for file in files:
            for c_file in file:
                if c_file.endswith(".c"):
                    c_file_list.append(c_file)


    if c_file_list != []:
        n = len(c_file_list)

        print(f"Found {n} C source files.")

        for i in range(n):
            print(f"{i+1}", c_file_list[i])

        print("Do you want to batch compile all the files or just a specific file?")
        ans = int(input("For first option type 1, or else type 2 for the second option: "))

        if ans == 1:
            print("Selected batch compiling.")
            print("Compiling all the files....")

            os.chdir(dir_path) # navigate to the input directory.

            for i in range(n):
                file_name = Path(c_file_list[i])
                print(f"Compiling {c_file_list[i]}")
                os.system(f"gcc {c_file_list[i]} -o {file_name.stem}")

        elif ans == 2:
            f_no = int(input("Enter file number as displayed: "))

            os.chdir(dir_path) # navigate to the input directory.

            file_name_sel = Path(c_file_list[f_no-1])
            print(f"Selected file: {c_file_list[f_no-1]}")
            print(f"Compiling {c_file_list[f_no-1]}....")
            os.system(f"gcc {c_file_list[f_no-n]} -o {file_name_sel.stem}")

        else:
            print("Wrong input.")
            sys.exit(0)

    else:
        print("No C files found in the specified path")
        sys.exit(0)

def check_gcc() -> int:

    # check for gcc 

    check_gcc = subprocess.call(["gcc", "--version"], shell=False)
    
    return check_gcc


gcc_status = check_gcc()


if gcc_status == 0:
    print("gcc executable found, continuing....")
    sleep(1)

    if platform.platform().startswith("Windows"):
        os.system("cls")
        main()

    else:
        os.system("clear")
        main()

else:
    print("gcc.exe not found, please install gcc. Exiting....")
    sys.exit(1)







