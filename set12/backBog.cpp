// void solveBoggle(vector<vector<char>>& tooD, string& s, pair<int, int> currP){
//     s += tooD[currP.first][currP.second];
//     visited[currP.first][currP.second] = true;

//     if(!Trie.findWord(s, s.size() - 1)){ // since we know s before we add the curr char is in the trie, we can set the ind arg to s.size() - 1 instead 
//         s.pop_back();
//         visited[currP.first][currP.second] = false;
//         return;
//     }
//     if(currP.first-1 >= 0 && currP.second-1 >= 0 && !visited[currP.first-1][currP.second-1]){
//         solveBoggle(tooD, s, {currP.first-1, currP.second-1});
//     }

//     s.pop_back();
//     visited[currP.first][currP.second] = false;
// }