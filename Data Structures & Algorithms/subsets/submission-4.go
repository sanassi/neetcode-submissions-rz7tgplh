func aux(nums []int, res *[][]int, tmp []int, i int) {
	if i >= len(nums) {
		cpy := make([]int,  len(tmp))
		copy(cpy, tmp)
		*res = append(*res, cpy)
		return
	}

	tmp = append(tmp, nums[i])
	aux(nums, res, tmp, i + 1)
	tmp = tmp[:len(tmp)-1]
	aux(nums, res, tmp, i + 1)
}

func subsets(nums []int) [][]int {
	res := make([][]int, 0)

	aux(nums, &res, make([]int, 0), 0)

	return res
}
