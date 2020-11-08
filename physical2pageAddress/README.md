
### Assumption
There is one Page table that can span the entire physical memory.

### How to get Page Number
```
2^32              ==> Total virtual memory size

4KB=2^12          ==> Size of a single page

2^32 / 2^12 =2^20 ==> Total number of pages of virtual memory

So page table will be having 2^20 = 1M entries


Current Page Number = ceil(physical Address / page Size)
```

<br/>
Used Ceil because Page addressing is not considered to be 0 indexed.
<br/>
<br/>

### How to get Physical Address of start of Page
```
pagePhysicalAddress = pageNumber * pageSize
```


<br/>
<br/>

### How to get Page Offset
```
offset = physical - pageSize * pageNumber
```