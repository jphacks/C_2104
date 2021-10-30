# シセイ小町

[![IMAGE ALT TEXT HERE](https://jphacks.com/wp-content/uploads/2021/07/JPHACKS2021_ogp.jpg)](https://www.youtube.com/watch?v=LUPQFB4QyVo)

## 製品概要
### 背景(製品開発のきっかけ、課題等）
    コロナによるオンライン化に伴い、学生はリモート授業や課題で、社会人はリモートワークで、PCに向き合う時間が大きく増加しました。これによって、"ストレートネック"や、肩こり、慢性的な頭痛など、多くの健康被害が出ています。
    そこで、日々自分の姿勢を意識することで、これらの苦痛から解放したいと思い「姿勢よしこちゃん」を製作しました。
### 製品説明（具体的な製品の説明）
    自分の姿勢と連動したキャラクターが現実世界(人形)とPC上(3Dモデル)にいて、自分の姿勢を客観的に見ることができます。
    また、一定時間姿勢が悪い状態が続くと、キャラクターが声で注意してくれて、キャラクターに注視していなくても姿勢が悪いことに気づくことができます。
### 特長
#### 1.姿勢が悪い状態が続くとキャラクターが声で注意してくれる！
作業中でも姿勢が悪いことに気づけるできるため、安心して作業に集中できます
#### 2.リアルタイムで自分の姿勢がわかる！
自分がいつもどんな姿勢をしているか再認識できるため、自分の健康を見直すきっかけにもなります
#### 3. 体の健康を維持できる！
姿勢を正すことで、ストレートネックや肩こりを軽減することができ、ネット社会でも健康に過ごせます

### 解決出来ること
* 自分の姿勢を客観的に見ることができ、ストレートネックや肩こりを予防できます
* 常にキャラクターが見守ってくれるので、寂しさを軽減できます

### 今後の展望
* 画像処理(YOLO, StereoVision)を使い、姿勢の特徴点を増やすことで、より正確な姿勢検知を実装する
* 人形の可動部を増やし、より正確な姿勢の再現を行う

### 注力したこと（こだわり等）
* 自分の姿勢に連動してキャラクターが動くので、姿勢を客観視することができます
* 3Dモデルと人形の二つを用意することで、PC作業中に限らず姿勢を気にすることができます

## 開発技術
### 活用した技術
#### API・データ
* [ミライ小町 blenderデータ](https://github.com/Miraikomachi)

#### フレームワーク・ライブラリ・モジュール
* [Unity](https://unity.com/ja)  
* Visual C#
* arduino
  * [Firebase-ESP32 library](https://github.com/mobizt/Firebase-ESP32)
  * [KalmanFilter library](https://github.com/TKJElectronics/KalmanFilter)
  * [M5Atom arduino library](https://github.com/m5stack/M5Atom)
  * [M5StickC arduino library](https://github.com/m5stack/M5StickC)
* blender
* Firebase

#### デバイス
* ESP32
* ANYCUBIC Photon Zero

### 独自技術
#### ハッカソンで開発した独自機能・技術
* 3Dプリントした「ミライ小町」人形が自分と同じ動きをしてくれる     commitID [```6039a99```](https://github.com/jphacks/C_2104/commit/da0eb2e1d18be8593c9153122020e9ca64a2f43d)
* 3Dモデルも自動で動き、姿勢が悪い状態が続くと声で注意してくれる　 commitID [```da0eb2e```](https://github.com/jphacks/C_2104/commit/da0eb2e1d18be8593c9153122020e9ca64a2f43d)
* カルマンフィルタを通した正確な姿勢データをFirebaseに送り、そこからソフト、ハードで現在の姿勢を検知する commitID [```2687e54```](https://github.com/jphacks/C_2104/commit/2687e54052617e940925f7b98bdfe8b83c8a72d4)

#### 製品に取り入れた研究内容（データ・ソフトウェアなど）（※アカデミック部門の場合のみ提出必須）
*
*
