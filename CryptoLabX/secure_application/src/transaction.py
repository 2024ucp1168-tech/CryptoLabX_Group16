from data import users, transactions


def check_balance(wallet_id):
    print("\nWallet ID:", wallet_id)
    print("Username:", users[wallet_id]["username"])
    print("Balance:", users[wallet_id]["balance"], "coins")

def send_transaction(sender_id):
    try:
        receiver_id = int(input("Enter receiver wallet ID: "))
        amount = float(input("Enter amount: "))
    except ValueError:
        print("Invalid input.")
        return

    if receiver_id not in users:
        print("Receiver wallet does not exist.")
        return

    if users[sender_id]["balance"] < amount:
        print("Insufficient balance.")
        return

    users[sender_id]["balance"] -= amount
    users[receiver_id]["balance"] += amount

    transactions.append({
        "sender": sender_id,
        "receiver": receiver_id,
        "amount": amount
    })

    print("\nTransaction successful!")
    print(amount, "coins sent to", users[receiver_id]["username"])


def show_transactions(wallet_id):
    print("\n========== TRANSACTION HISTORY ==========")

    found = False

    for transaction in transactions:
        if transaction["sender"] == wallet_id or transaction["receiver"] == wallet_id:
            found = True

            sender = users[transaction["sender"]]["username"]
            receiver = users[transaction["receiver"]]["username"]
            amount = transaction["amount"]

            print(sender, "->", receiver, ":", amount, "coins")

    if not found:
        print("No transactions found.")