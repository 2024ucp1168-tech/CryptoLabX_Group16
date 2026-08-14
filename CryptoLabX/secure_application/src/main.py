from auth import create_wallet, login
from transaction import check_balance, send_transaction, show_transactions


def wallet_menu(wallet_id):
    while True:
        print("\n================================")
        print("          WALLET MENU")
        print("================================")
        print("1. Check Balance")
        print("2. Send Transaction")
        print("3. Transaction History")
        print("4. Logout")

        choice = input("Enter choice: ")

        if choice == "1":
            check_balance(wallet_id)

        elif choice == "2":
            send_transaction(wallet_id)

        elif choice == "3":
            show_transactions(wallet_id)

        elif choice == "4":
            print("\nLogged out.")
            break

        else:
            print("Invalid choice.")


def main():
    while True:
        print("\n================================")
        print("       CRYPTOCURRENCY WALLET")
        print("================================")
        print("1. Create Wallet")
        print("2. Login")
        print("3. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            create_wallet()

        elif choice == "2":
            wallet_id = login()

            if wallet_id is not None:
                wallet_menu(wallet_id)

        elif choice == "3":
            print("\nThank you for using Crypto Wallet.")
            break

        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()