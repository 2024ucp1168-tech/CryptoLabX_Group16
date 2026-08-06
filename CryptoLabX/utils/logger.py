from datetime import datetime
import os


LOG_FILE = os.path.join("outputs", "activity.log")


def write_log(option):

    now = datetime.now()

    with open(LOG_FILE, "a") as f:
        f.write(
            f"{now.strftime('%Y-%m-%d %H:%M:%S')} -> {option}\n"
        )