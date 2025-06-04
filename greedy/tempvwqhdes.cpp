
// int meetingRooms(vector<vector<int>> & intervals){
//     vector<int> start;
//     vector<int> end;
//     for(int i = 0 ; i < intervals.size() ; i++){
//         start.push_back(intervals[i][0]);
//         end.push_back(intervals[i][1]);
//     }

//     sort(start.begin(),start.end());
//     sort(end.begin(), end.end());

//     int i = 0 ; int j = 0 ;
//     int rooms = 0;

//     while (i < start.size()){
//         if(start[i] < end[j]){
//             rooms++;
//             i++;
//         } else {
//             j++;
//         }
//     }

//     return rooms;
// }
