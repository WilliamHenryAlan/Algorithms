class Node:
	def __init__(self,data = 0):
		self.data = data
		self.next = None
class LinkedList:
	def __init__(self):
		self.head = Node()
	def isempty(self):
		return self.head.next == None

LinkedList = LinkedList()
print(LinkedList.isempty())

#     def is_empty(self):
#         return self.head is None

#     def insert_at_beginning(self, data):
#         new_node = Node(data)
#         new_node.next = self.head
#         self.head = new_node

#     def insert_at_end(self, data):
#         new_node = Node(data)
#         if self.is_empty():
#             self.head = new_node
#         else:
#             temp = self.head
#             while temp.next is not None:
#                 temp = temp.next
#             temp.next = new_node

#     def delete_node(self, data):
#         if self.is_empty():
#             return
        
#         if self.head.data == data:
#             self.head = self.head.next
#             return
        
#         prev = None
#         temp = self.head
#         while temp is not None and temp.data != data:
#             prev = temp
#             temp = temp.next
        
#         if temp is None:
#             return
        
#         prev.next = temp.next

#     def display(self):
#         if self.is_empty():
#             print("LinkedList is empty")
#             return
        
#         temp = self.head
#         while temp is not None:
#             print(temp.data, end=" ")
#             temp = temp.next
#         print()

# # 测试单链表
# linked_list = LinkedList()
# linked_list.insert_at_beginning(3)
# linked_list.insert_at_beginning(2)
# linked_list.insert_at_beginning(1)

# linked_list.display()  # 输出: 1 2 3

# linked_list.insert_at_end(4)
# linked_list.insert_at_end(5)

# linked_list.display()  # 输出: 1 2 3 4 5

# linked_list.delete_node(3)
# linked_list.display()  # 输出: 1 2 4 5

# linked_list.delete_node(1)
# linked_list.display()  # 输出: 2 4 5

