class Client:
    def __init__(self, name, phone):
        self.name = name
        self.phone = phone

    def __str__(self):
        return f"Name: {self.name}, Phone: {self.phone}"


class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash_function(self, key):
        return sum(ord(char) for char in key) % self.size

    def insert(self, client):
        key = client.name
        index = self._hash_function(key)
        slot = self.table[index]
        for existing_client in slot:
            if existing_client.name == client.name:
                existing_client.phone = client.phone
                return
        slot.append(client)

    def search(self, name):
        index = self._hash_function(name)
        for client in self.table[index]:
            if client.name == name:
                return client
        return None

    def display(self):
        for i, slot in enumerate(self.table):
            print(f"Slot {i}:")
            for client in slot:
                print(client)
            print()

    def get_collision_count(self):
        collision_count = 0
        for slot in self.table:
            if len(slot) > 1:
                collision_count += len(slot) - 1
        return collision_count


def create_client():
    name = input("Enter client name: ")
    phone = input("Enter client phone number: ")
    return Client(name, phone)


def main():
    size = int(input("Enter the size of the hash table: "))
    hash_table = HashTable(size)

    num_clients = int(input("Enter the number of clients: "))
    for _ in range(num_clients):
        client = create_client()
        hash_table.insert(client)

    print("\nHash Table:")
    hash_table.display()

    search_name = input("Enter the client name to search: ")
    client = hash_table.search(search_name)
    if client:
        print("Client found:")
        print(client)
    else:
        print("Client not found.")

    collision_count = hash_table.get_collision_count()
    print("Collision count:", collision_count)


if __name__ == "__main__":
    main()
