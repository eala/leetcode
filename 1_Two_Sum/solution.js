/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var result = new Array(2);
    for(i =0 ; i< (nums.length-1) ; i++){
        for(j = i+1 ; j < nums.length; j++) {
            if( nums[i] + nums[j] === target){
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }
    return result;
};