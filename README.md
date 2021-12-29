## RC4

- 정의
rc4 암호화는 매우 간단하게 소프트웨어로 구현할 수 있는 스트림 암호화 기법이다.
40~128 bit (5~16 byte) 길이의 키를 이용해 0~255 까지 256개의 수의 순열을 만들고 이를 활용하여 랜덤에 가까운 방식으로 바이트 스트림을 암호화한다.
- 사용 예시

  1. 프로젝트내에 암호화할 파일을 생성한 후 암호화 진행

<img src = "https://user-images.githubusercontent.com/81247213/147633658-4aa0598b-bfae-4ff2-a5ac-276088c799e6.png" width="250" height="100" />

  2. key로 사용할 임의의 값 입력하면 key_streambyte와 암호화문이 나타난다.
<img src = "https://user-images.githubusercontent.com/81247213/147633658-4aa0598b-bfae-4ff2-a5ac-276088c799e6.png" width="250" height="100" />
<img src = "https://user-images.githubusercontent.com/81247213/147633977-1af78df7-1d87-4c93-a58d-821f08aa0c56.png" width="250" height="100" />

  3. 사용하였던 key값을 다시입력하면 복호화 된다.
<img src = "https://user-images.githubusercontent.com/81247213/147634045-969ae287-0765-4d1d-8fd9-27ff29ff8e02.png" width="250" height="100" />
<img src = "https://user-images.githubusercontent.com/81247213/147634053-36bfc989-41ec-40aa-97fd-60e63e5d6345.png" width="250" height="100" />
  
  


- 활용 
  - PDF
  - WEP
  - SSL
  - RDP

- method
  - KSA() : swapping을 위한 byte array 초기화
  - PRGA() : 참조 테이블 배열을 이요해 key byte 생성
  - encryption() : 생성된 key와 입렫되는 byte를 XOR 연산을 통해 암호화/복호화
 
- RC4 취약점
  - 확률분포가 고르게 나타나지않는다.
  - 실제 실험에서 RC4의 확률은 2/256이다.
  - 이는 RC4를 사용하여 메시지를 암호화하면, 두번째 바이트는 제대로 암호화가 되지 않을 가능성이 있다는 의미이다. 또한, 이를 토배로 앞 뒤의(1번째와 3번째) 바이트들을 분석하면 그 또한 편향 되었는지 아닌지를 추정할 수 있다. 


