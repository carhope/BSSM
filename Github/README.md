# Github 개념과 용어, 명령어 정리
## 가장 중요한 명령어 top10
1. git status
2. git add
3. git commit
4. git push
5. git pull
6. git log
7. git branch
8. git checkout (또는 git switch)
9. git remote
10. git fetch- 

### git add .

변경된 파일을 스테이징 영역(Staging Area) 에 추가한다.
(커밋하기 전에 "이 파일들을 저장할 거야"라고 표시하는 과정)

### git commit -m "메시지"

- 스테이징된 내용을 하나의 버전(스냅샷) 으로 저장한다.

### git push

- 로컬 저장소 → GitHub 원격 저장소 로 업로드한다.

### git pull

- GitHub의 최신 변경사항을 가져오고 자동으로 병합(Merge) 한다.

### git fetch

- 원격 저장소의 최신 내용을 가져오기만 한다.

- 내 코드에는 아무 변화가 없다.

### git log

- 또는

### git log --oneline

- 커밋 기록을 확인한다.

### git branch

- 브랜치를 확인하거나 생성한다.

### git checkout 브랜치명

- 다른 브랜치로 이동한다.

- 또는

### git checkout 파일명

### ※ 요즘은

- git switch

와

- git restore

를 더 많이 사용한다.

### git merge 브랜치명
- 다른 브랜치 내용을 현재 브랜치 내용과 합치기

### 브랜치 개념
- 협업을 할때에는 서로 충돌이 일어 날 수 있기 때문에 우선 서로 다른 길을 만들어 그곳에 충돌하지 않고 작업한 다음 작업한걸 합친다.

### git remote -v
- 연결된 원격 저장소(Github등) 확인

### 추가
- git remote add origin 주소

### 삭제
- git remote remove origin

- 이번 repo 통합으로 배운거

### git subtree

#### git subtree add --prefix=옮길특정파일 가져올저장소 main
- 다른 Git 저장소의 커밋 기록과 파일들을 현재 저장소로 가져와 특정 폴더와 합침
- 현재 저장소 터미널에서 시도하기

### git mv
- git mv old new
- Git이 이동사실을 추적하며 파일 이동
- 즉, mv는 파일이동이고 이걸 한걸 git에게 같이 한번에 알려줌.

### git status
- 현재 변경 사항 확인