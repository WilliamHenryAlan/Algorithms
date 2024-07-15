class MyCircularQueue {
    k: number = 0;start :number = 0;end: number = 0;//this.end指向待插入位置
    data: number [];
    constructor(k: number) {
        this.k = k
        this.data = new Array<number>(k)
    }
    enQueue(value: number): boolean {
        if (this.isFull()) return false;
        this.data[this.end % this.k] = value//通过mod确认实际插入位置
        return this.end++ >= 0   
    }
    deQueue(): boolean {
        if(this.isEmpty()) return false
        this.start++;
        return true;
    }
    Front(): number {
        return this.isEmpty()?-1:this.data[this.start % this.k]
    }
    Rear(): number {
        return this.isEmpty()?-1:this.data[(this.end - 1) % this.k]
    }
    isEmpty(): boolean {
        return this.start == this.end   
    }
    isFull(): boolean {
        return this.end - this.start == this.k   
    }
}

