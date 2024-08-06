/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let i = num1.length - 1,j = num2.length - 1,carry = 0;
    const ans = [];
    for (;i >= 0 || j >= 0 || carry != 0;i--,j--) {
        const x = i >= 0?num1.charAt(i) - '0':0;
        const y = j >= 0?num2.charAt(j) - '0':0;
        const sum = x + y + carry;
        if (sum > 9) carry = 1;
        else carry = 0;
        ans.push(sum % 10);
    }
    return ans.reverse().join('');
};
