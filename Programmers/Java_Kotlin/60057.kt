class Solution {
    fun solution(s: String): Int {
        var answer = 1001

        for(len in 1..s.length) {
            val temp = StringBuilder()
            val stack = mutableListOf<String>(s.substring(0,len))

            for(idx in len..2000 step len) {
                if(idx >= s.length){
                    if(stack.size == 1)
                        temp.append("${stack.lastOrNull()}")
                    else
                        temp.append("${stack.size}${stack.lastOrNull()}")
                    break;
                }

                val end = if(idx+len <= s.length) idx+len else s.length
                val sub = s.substring(idx,end)

                if(stack.isEmpty())
                    stack.add(sub)
                if(sub == stack.lastOrNull())
                    stack.add(sub)
                else {
                    if(stack.size == 1)
                        temp.append("${stack.lastOrNull()}")
                    else
                        temp.append("${stack.size}${stack.lastOrNull()}")

                    stack.clear()
                    stack.add(sub)
                }


            }

            if(temp.length < answer) {
                answer = temp.length
            }
        }

        return answer
    }
}