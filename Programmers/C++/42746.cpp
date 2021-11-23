bool cmp(int& a, int& b)
{
    return a + b > b + a;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumbers;
    for (int i = 0; i < numbers.size(); i++) {
        strNumbers.push_back(to_string(numbers[i]));
    }
    sort(strNumbers.begin(), strNumbers.end(), cmp);
    if (strNumbers[0].compare("0") == 0)
        return "0";

    for (int i = 0; i < strNumbers.size(); i++) {
        answer += strNumbers[i];
    }
    return answer;
}