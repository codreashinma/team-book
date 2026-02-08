# iOS小説（グラフィックデザイナー→iOSエンジニア）

小説の本文・プランは **articles 内** に配置する。

## 命名規則

- 本文: `shohei_cha_01.re`, `shohei_cha_02.re`, … （`shohei_cha_NN.re`）
- プラン: `shohei_cha_01.plan.md`, `shohei_cha_02.plan.md`, …

## 新章を追加するとき

1. `shohei_cha_02.re` などを articles に作成する
2. `catalog.yml` の `CHAPS:` に、追加したファイル名を1行で追記する

例:

```yaml
CHAPS:
  - okihara.re
  - 01_chapter01.re
  - okihara_01.re
  - shohei_cha_01.re
  - shohei_cha_02.re   # 第2章を追加した場合
```
