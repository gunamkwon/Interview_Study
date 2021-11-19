vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, bool> map;
    int turn = 2;
    int game = 1;
    // 단어 다르거나
    // 중복 되거나
    map.insert(make_pair(words[0], true));

    for (int i = 1; i < words.size(); i++) {
        if ((words[i - 1][words[i - 1].length() - 1] != words[i][0])
            || (map[words[i]] == true)
            || words[i].size() == 1) {
            answer.push_back(turn);
            answer.push_back(game);
            break;
        }

        if (turn == n) {
            game++;
            turn = 1;
        }
        else turn++;
        map[words[i]]=true;
    }

    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}