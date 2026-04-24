/**
 * Definition of Interval:
 * type Interval struct {
 *    start int
 *    end   int
 * }
 */

 import ( 
    "slices"
    "cmp"
 )

func canAttendMeetings(intervals []Interval) bool {
    sortFunc := func (a, b Interval) int {
        return cmp.Compare(a.start, b.start)
    }

    slices.SortFunc(intervals, sortFunc)

    fmt.Println(intervals)

    for idx, intv := range intervals {
        if idx + 1 < len(intervals) {
            next := intervals[idx + 1]
            if next.start < intv.end {
                return false
            }
        }
    }

    return true
}
