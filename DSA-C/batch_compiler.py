import os
import subprocess
import platform
from pathlib import Path
import sys
from time import sleep

PLATFORM_TYPE = ""


def main() -> None:

    global PLATFORM_TYPE

    print("C source files batch compiler. Compile multiple files altogether.")
    print("v1.0")

    dir_path = input("Enter source directory path: ")

    c_file_list = []
    bin_file_list = []

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

        print("\n")
        print("1. Batch compilation (Compile all files at once)")
        print("2. Compile a specific file.")
        print("3. Run a specific file")

        ans = int(input("For first option type 1, or else type 2 for the second option or else type 3 for the third option: "))

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
            os.system(f"gcc {c_file_list[f_no-1]} -o {file_name_sel.stem}")

        elif ans == 3:

            os.chdir(dir_path) # navigate to the input directory

            if PLATFORM_TYPE == "Windows":
                for files in os.walk(dir_path):
                    for file in files:
                        for bin_file in file:
                            if bin_file.endswith(".exe"):
                                bin_file_list.append(bin_file)

                if bin_file_list != []:
                    n1 = len(bin_file_list)

                    print(f"Found {n1} exe files.")

                    for i in range(n1):
                        print(f"{i+1}", bin_file_list[i])


                    f_no = int(input("Enter file number as displayed: "))
                    print(f"Selected file: {bin_file_list[f_no-1]}")
                    os.system("cls")
                    print(f"Output of file {bin_file_list[f_no-1]}: ")
                    os.system(f"{bin_file_list[f_no-1]}")



            elif PLATFORM_TYPE == "UNIX":
                for files in os.walk(dir_path):
                    for file in files:
                        for bin_file in file:
                            if bin_file.endswith(".out"):
                                bin_file_list.append(bin_file)


                for files in os.walk(dir_path):
                    for file in files:
                        for bin_file in file:
                            if bin_file.endswith(".out"):
                                bin_file_list.append(bin_file)

                if bin_file_list != []:
                    n1 = len(bin_file_list)

                    print(f"Found {n1} .out files.")

                    for i in range(n1):
                        print(f"{i+1}", bin_file_list[i])


                    f_no = int(input("Enter file number as displayed: "))
                    print(f"Selected file: {bin_file_list[f_no-1]}")
                    os.system("clear")
                    print(f"Output of file {bin_file_list[f_no-1]}: ")
                    os.system(f"{bin_file_list[f_no-1]}")



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
        PLATFORM_TYPE = "Windows"
        os.system("cls")
        main()

    else:
        PLATFORM_TYPE = "UNIX"
        os.system("clear")
        main()

else:
    print("gcc.exe not found, please install gcc. Exiting....")
    sys.exit(1)







