import requests

url='https://api.github.com/search/repositories?q=language:python&sort=stars'
r=requests.get(url)
print('Status code:',r.status_code)

response_dict=r.json()
print('Total repositories:',response_dict['total_count'])

#探索仓库的相关信息
repo_dicts=response_dict['items']
print('Repositories returned:',len(repo_dicts))


for repo_dict in repo_dicts:
    print()