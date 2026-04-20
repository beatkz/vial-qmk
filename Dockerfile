# QMK公式のCLIイメージをベースに使用
FROM ghcr.io/qmk/qmk_cli@sha256:2dc05fc9f32efebd6b05c2b8676ee548358bc7e151e9dbf4dac6b6eed4513b07

# ビルドに必要な追加パッケージがあればここでインストール
# PEP 668対策を施しつつ、vial-qmkのrequirementsをインストール
USER root
WORKDIR /qmk_firmware
