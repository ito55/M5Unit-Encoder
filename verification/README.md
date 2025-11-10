# M5Unified対応Unit Encoder Example sketch 動作確認資料

このドキュメントは、新しいExampleスケッチ `[Unit_Encoder_M5Unified.ino]` の動作確認手順を説明するものです。
ご協力いただきありがとうございます！

**Pull Request:** [[Feature/example: Add M5Unified compatible example sketch (v0.0.3)](https://github.com/m5stack/M5Unit-Encoder/pull/7)]

---

## 1. 目的

 `M5Unified` ライブラリを用いた新しいExampleスケッチがM5Stackの様々な機種で意図通りに動作することを確認します。

## 2. 準備するもの

- **ハードウェア:**
  - いずれかのM5Stackデバイス (Core, Core2, CoreS3, ATOM, StickCなど)
  - M5Stack Unit Encoder (SKU: U135)

- **ソフトウェア (Arduino IDEの場合):**
  - Arduino IDE
  - ESP32ボード定義
  - **M5Unified** ライブラリ (最新版)
  - **M5Unit-Encoder** ライブラリ (Library Managerで普通に導入できる最新版)

## 3. テスト手順

1.  **ライブラリの準備:**

    Arduino IDEで下記Libraryを導入します。
    - [M5Unified](https://github.com/m5stack/M5Unified)
    - [M5Unit-Encoder](https://github.com/m5stack/M5Unit-Encoder)

2.  **スケッチの準備と書き込み:**
    - Arduino IDEで新規スケッチを作成します。
    - [こちらのソースコード](https://github.com/ito55/M5Unit-Encoder/blob/verify/example-m5unified/examples/Unit_Encoder_M5Unified/Unit_Encoder_M5Unified.ino)の内容をすべてコピーし、作成した新規スケッチに貼り付けます。
    - ご使用のM5Stackデバイスに合わせて、ボードとシリアルポートを選択します。
    - スケッチをデバイスに書き込みます。

3.  **動作確認:**
    - シリアルモニタを開きます (ボーレート: 115200)。
    - Unit Encoderを操作します。

## 4. 期待される動作

- 画面表示内容に変化がある。
- Serial Portへ数値が出力される。
- Unit Encoderの操作に応じて、LEDの色が変化する。

## 5. 結果の報告

動作確認が完了しましたら、結果を[Pull Request](https://github.com/m5stack/M5Unit-Encoder/pull/7)へのコメントでお知らせください。

- **正常に動作した場合:**
  - 「（お使いのボード名）で正常に動作しました」といった簡単なコメントをいただけると幸いです。

- **不具合があった場合:**
  - 以下の情報を添えて、私宛にご報告ください。
    - 使用したボード名 (例: M5Stack Core2)
    - シリアルモニタの出力内容
    - どのような問題が発生したかの具体的な説明

## 6. このbranchとフォルダの取り扱い方針

この`verification`フォルダと、このファイルを含むブランチは動作確認用のものです。
そのため、最終的なPull Requestには含まれません。
