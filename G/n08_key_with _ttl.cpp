#include <iostream>

// Create a map with expiring entries: 
// Example
// 12:00:00 - put(10, 25, 5000) 
// 12:00:04 - get(10) -> 25 
// 12:00:06 - get(10) -> null

// 思路：两个hash map，一个记录key，value pair，一个记录key的过期时间，get的时候检查key是否过期，如果过期了，删除key返回null
// Put方法有三个参数，除了key，value还有个duration



int main() {

}