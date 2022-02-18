class Solution {
    fun solution(s: String): MutableList<Int> {
        var answer = mutableListOf<Int>()
        val tempSet = mutableListOf<Int>()
        val temp = IntArray(100000) { _ -> 0 }
        var str = s.replace('{',',')
        str = str.replace('}',',')
        val strNum = str.split(',')


        for(num in strNum) {
            if(num != ""){
                temp[num.toInt()]++
                if(!tempSet.contains(num.toInt())) tempSet.add(num.toInt())
            }
        }

        tempSet.sortWith(compareByDescending { temp[it] })

        for(idx in 0 until tempSet.size)
            answer.add(tempSet.elementAt(idx))
        return answer
    }
}