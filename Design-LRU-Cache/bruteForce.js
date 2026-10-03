
class LRUCache {

    constructor(capacity) {
        this.cache = [];
        this.n = capacity;
    }

    // get = () => {

    // }

    get(key) {
        
        for (let i = 0; i < this.cache.length; i++) {

            if (this.cache[i][0] === key) {
                let val = this.cache[i][1];

                this.cache.splice(i, 1);
                this.cache.push([key, val]);

                return val;
            }
        }

        return -1;
    }

    put(key, value) {

        for (let i = 0; i < this.cache.length; i++) {

            if (this.cache[i][0] === key) {
                this.cache.splice(i, 1);
                this.cache.push([key, value]);

                return;
            }
        }

        if (this.cache.length === this.n) {
            this.cache.shift();
        }

        this.cache.push([key, value]);
    }
}


function main() {

        
    const obj = new LRUCache(2);

    console.log("========== LRU Cache Test ==========");

    console.log("\n[1] put(1, 1)");
    obj.put(1, 1);
    console.log("Inserted key = 1, value = 1");


    console.log("\n[2] put(2, 2)");
    obj.put(2, 2);
    console.log("Inserted key = 2, value = 2");


    console.log("\n[3] get(1)");
    console.log("Result:", obj.get(1));


    console.log("\n[4] get(2)");
    console.log("Result:", obj.get(2));


    console.log("\n[5] put(2, 3)");
    obj.put(2, 3);
    console.log("Updated key = 2, value = 3");


    console.log("\n[6] get(2)");
    console.log("Result:", obj.get(2));


    console.log("\n[7] put(3, 3)");
    obj.put(3, 3);
    console.log("Inserted key = 3, value = 3");
    console.log("Since capacity = 2, LRU key should be removed.");


    console.log("\n[8] get(3)");
    console.log("Result:", obj.get(3));


    console.log("\n[9] get(1)");
    console.log("Result:", obj.get(1));


    console.log("\n====================================");

}

main();