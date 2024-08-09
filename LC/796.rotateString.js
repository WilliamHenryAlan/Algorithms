/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function(s, goal) {
    let n = goal.length,a = [],b = [];
    for (let i = 0;i < n;i++) {
        if (goal[i] == s[0]) {
            a = goal.substr(i,n - i);
            b = goal.substr(0,i);
            if (a + b == s) return true;
        }
    }
    return false;
};
