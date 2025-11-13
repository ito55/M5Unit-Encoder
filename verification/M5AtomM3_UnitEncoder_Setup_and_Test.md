# M5AtomS3 Unit Encoder サンプルスケッチ動作確認ガイド

## 目的

Unit Encoder 用に新規作成した M5Unified 向けサンプルスケッチが、**M5AtomS3**で正しく動作することを確認します。してください。

---

## 背景（M5Unified への移行について）

M5Stack の周辺機器ライブラリは、現在 M5Unified への統合が進められています。M5Stack 公式もこの共通ライブラリの利用を推奨していますが、現状では周辺機器向けの古いサンプルスケッチが M5Unified 向けに書き換えられていないものが多く残っています。

今回動作確認の対象となる Unit Encoder のライブラリも同様です。このため、新規作成した M5Unified 向けのサンプルスケッチが、様々なコントローラー（今回の場合 M5AtomS3）で正しく動作するかを確認したいというのが本手順の背景です。私の環境 M5Stack Core2 V1.1 では動作確認済みです。HRD君にも依頼済みで、彼はM5Stack-Coreを持っています。

---

## 手順概要

**ポイント：** Arduino IDE の Library Manager で **M5AtomS3 を導入**する代わりに、**M5Unified ライブラリ**を導入します。

1.  Arduino IDE をインストール
2.  Board Manager で M5Stack のボードパッケージを導入
3.  Library Manager で **M5Unified** ライブラリを導入 **M5AtomS3ではないのがポイント**
4.  Library Manager で Unit Encoder ライブラリを導入
5.  GitHub から動作確認対象のサンプルスケッチを入手
6.  Arduino IDE でスケッチを M5AtomS3 へ書き込み、動作確認
7.  GitHub の Draft PR へ確認結果を報告

---

## 手順詳細

### 1. Arduino IDE のインストール

[M5Stack 公式ドキュメントのリンク](https://docs.m5stack.com/en/arduino/arduino_ide)を参照し、**手順 1 のみ**を実施して Arduino IDE をインストールします。

### 2. Board Manager で M5Stack を導入

[M5Stack 公式ドキュメントのリンク](https://docs.m5stack.com/en/arduino/arduino_board)を参照し、**「1. Installing Board Management」**の手順を実施して M5Stack のボードパッケージを導入します。

### 3. Library Manager で M5Unified を導入

[M5Stack 公式ドキュメントのリンク](https://docs.m5stack.com/en/arduino/m5unified/helloworld)を参照し、**「Preparation 3」**の手順を実施して M5Unified ライブラリを導入します。

### 4. Library Manager で Unit Encoder を導入

Arduino IDE のライブラリマネージャーを開き、**「Unit Encoder」**を検索してインストールします。インストールされるバージョンは **0.0.2** であるはずです。

### 5. GitHub から動作確認対象のサンプルスケッチを入手

以下の GitHub リンクから、動作確認対象のサンプルスケッチ **`Unit_Encoder_M5Unified.ino`** を入手してください。

https://github.com/ito55/M5Unit-Encoder/blob/feature/example-m5unified/examples/Unit_Encoder_M5Unified/Unit_Encoder_M5Unified.ino

### 6. Arduino IDE でスケッチを M5AtomS3 へ書き込み、動作確認

入手したスケッチを Arduino IDE で開き、M5AtomS3 を選択して書き込み（アップロード）を行い、正しく動作することを確認します。

### 7. GitHub の Draft PR へ確認結果を報告

動作確認の結果（成功/失敗、気づいた点など）を、以下の GitHub の Draft Pull Request (PR) へコメントとして報告してください。

https://github.com/m5stack/M5Unit-Encoder/pull/7