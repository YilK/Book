## 第6章 字典

### 遍历字典

1. #### 遍历所有的键-值对 ：dict.items()

```python
user = {
    'username': 'aaa',
    'age': 20,
    'IQ': 145
}
for key,value in user.items():
    print('Key:',key)
    print('Value:',value)
    
#输出
Key: username
Value: aaa
Key: age
Value: 20
Key: IQ
Value: 145
```



2. #### 遍历字典中的所有的键 ：dict.keys()

```python
user = {
    'username': 'aaa',
    'age': 20,
    'IQ': 145
}
for key in user.keys():
    print('Key:',key)

print(user.keys())

#输出
Key: username
Key: age
Key: IQ
dict_keys(['username', 'age', 'IQ'])
```



3. #### 遍历字典中所有的值

```python
user = {
    'username': 'aaa',
    'age': 20,
    'IQ': 145
}
for value in user.values():
    print('Value:',value)

print(user.values())

#输出
Value: aaa
Value: 20
Value: 145
dict_values(['aaa', 20, 145])
```



### 嵌套

1. 在列表中存放字典
2. 在字典中存储列表
3. 在字典中存储字典