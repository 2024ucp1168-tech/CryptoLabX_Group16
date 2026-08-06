from utils.logger import write_log
from utils.file_analysis import analyze_file


def menu():

    while True:
        print("\n========== CryptoLabX ==========")
        print("1. Encrypt")
        print("2. Decrypt")
        print("3. Attack")
        print("4. Analyze File")
        print("5. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            print("\nComing Soon...")
            write_log("Encrypt")

        elif choice == "2":
            print("\nComing Soon...")
            write_log("Decrypt")

        elif choice == "3":
            print("\nComing Soon...")
            write_log("Attack")

        elif choice == "4":
            write_log("Analyze")

            filename = input("Enter filename inside datasets/: ")

            analyze_file(filename)

        elif choice == "5":
            write_log("Exit")
            print("Goodbye!")
            break

        else:
            print("Invalid Choice")