import java.util.*

class Solution {
    fun solution(record: Array<String>): Array<String> {
        var answer = arrayOf<String>()

        var cmdMessages = arrayOf<Pair<String,String>>()
        val nickNameMap = hashMapOf<String,String>()

        for(command in record) {
            val strArray = command.split(" ")

            when(strArray[0]) {
                "Change" -> {
                    nickNameMap[strArray[1]] = strArray[2]
                }
                "Enter" -> {
                    cmdMessages = cmdMessages.plus(Pair(strArray[0],strArray[1]))
                    nickNameMap[strArray[1]] = strArray[2]
                }
                "Leave" -> {
                    cmdMessages = cmdMessages.plus(Pair(strArray[0],strArray[1]))
                }
            }
        }

        for(message in cmdMessages) {
            when(message.first) {
                "Enter" -> {
                    answer = answer.plus("${nickNameMap[message.second]}님이 들어왔습니다.")
                }
                "Leave" -> {
                    answer = answer.plus("${nickNameMap[message.second]}님이 나갔습니다.")
                }
            }
        }

        return answer
    }

}

fun main() {
    var record = arrayOf<String>("Enter uid1234 Muzi")
    val solution = Solution()
    solution.solution(record)
}