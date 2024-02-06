/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let l = 0;
    let r = height.length - 1;
    let volume = 0;
    while (l < r) {
        let temp = Math.min(height[l],height[r]) * (r - l);
        volume = Math.max(temp,volume);
        if (height[l] >= height[r]) r--;
        else l++
    }
    return volume;
};

let test1 = [1,8,6,2,5,4,8,3,7]
console.log("hello javascript")
console.log(maxArea(test1));

/*
tips:
1.js中length不是函数操作
2.max和min函数在Math库中
3.；可选
*/