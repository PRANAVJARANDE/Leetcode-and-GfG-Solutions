import happybase

# Connect to HBase
connection = happybase.Connection('localhost', 9090)

def create_orders_table(connection):
    table_name = 'Orders'
    
    families = {
        'user': dict(),
        'order': dict()
    }
    
    if table_name.encode() not in connection.tables():
        connection.create_table(table_name, families)
        print("Table created successfully!")
    else:
        print("Table already exists!")

def insert_sample_data(connection):
    table = connection.table('Orders')
    
    table.put(b'5001', {
        b'user:user_id': b'101',
        b'user:user_name': b'Asha',
        b'user:city': b'Bengaluru',
        b'order:product_name': b'Keyboard',
        b'order:amount': b'1499.00',
        b'order:order_date': b'2026-03-10'
    })
    
    table.put(b'5002', {
        b'user:user_id': b'101',
        b'user:user_name': b'Asha',
        b'user:city': b'Bengaluru',
        b'order:product_name': b'Mouse',
        b'order:amount': b'799.00',
        b'order:order_date': b'2026-03-12'
    })
    
    table.put(b'5003', {
        b'user:user_id': b'102',
        b'user:user_name': b'Rahul',
        b'user:city': b'Chennai',
        b'order:product_name': b'Monitor',
        b'order:amount': b'12999.00',
        b'order:order_date': b'2026-03-14'
    })
    
    print("Data inserted successfully!")

def get_order_details(connection, order_id):
    table = connection.table('Orders')
    
    row = table.row(str(order_id).encode())
    
    if not row:
        print("Order not found")
        return
    
    print("\nOrder Details:")
    print("User ID:", row[b'user:user_id'].decode())
    print("User Name:", row[b'user:user_name'].decode())
    print("City:", row[b'user:city'].decode())
    print("Order ID:", order_id)
    print("Product:", row[b'order:product_name'].decode())
    print("Amount:", row[b'order:amount'].decode())
    print("Date:", row[b'order:order_date'].decode())


# Run everything
create_orders_table(connection)
insert_sample_data(connection)
get_order_details(connection, 5001)
