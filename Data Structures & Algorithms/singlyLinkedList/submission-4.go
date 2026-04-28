type Node struct {
	next *Node
	val int
}

type LinkedList struct {
	head *Node
}

func NewLinkedList() *LinkedList {
	return &LinkedList{}
}

func (ll *LinkedList) Get(index int) int {
	tmp := ll.head
	idx := 0

	for tmp != nil {
		if idx == index {
			break
		}
		idx += 1
		tmp = tmp.next
	}

	if tmp == nil {
		return -1
	}

	return tmp.val
}

func (ll *LinkedList) InsertHead(val int) {
	head := ll.head

	n := &Node{val: val}

	n.next = head
	ll.head = n
}

func (ll *LinkedList) InsertTail(val int) {
	head := ll.head

	if head == nil {
		ll.head = &Node{val: val}
		return
	}

	for head.next != nil {
		head = head.next
	}

	head.next = &Node{val: val}
}

func (ll *LinkedList) Remove(index int) bool {
	tmp := ll.head

	if tmp == nil {
		return false
	}

	if index == 0 {
		ll.head = tmp.next
		return true
	}

	i := 1
	for i < index && tmp.next != nil {
		i++
		tmp = tmp.next
	}

	if tmp == nil || tmp.next == nil {
		return false
	}

	tmp.next = tmp.next.next

	//fmt.Printf("%v, %v", i, tmp.val)

	return true
}

func (ll *LinkedList) GetValues() []int {
	res := make([]int, 0)

	head := ll.head

	for head != nil {
		res = append(res, head.val)
		head = head.next
	}

	return res
}
