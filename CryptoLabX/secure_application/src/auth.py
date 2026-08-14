from data import users


def create_wallet():
    username = input("Enter username: ")
    password = input("Enter password: ")

    for user in users.values():
        if user["username"] == username:
            print("Username already exists.")
            return

    wallet_id = max(users.keys()) + 1

    users[wallet_id] = {
        "username": username,
        "password": password,
        "balance": 1000.0
    }

    print("\nWallet created successfully!")
    print("Wallet ID:", wallet_id)
    print("Initial Balance: 1000 coins")


def login():
    username = input("Enter username: ")
    password = input("Enter password: ")

    for wallet_id, user in users.items():
        if user["username"] == username and user["password"] == password:
            print("\nLogin successful!")
            print("Welcome,", username)
            return wallet_id

    print("\nInvalid username or password.")
    return None