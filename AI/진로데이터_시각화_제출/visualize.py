"""연도별 변화 선 그래프. 실행: python visualize.py (matplotlib 필요)"""
import csv
from pathlib import Path
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib import font_manager

ROOT = Path(__file__).resolve().parent
available = {font.name for font in font_manager.fontManager.ttflist}
for font in ["AppleGothic", "Malgun Gothic", "NanumGothic", "Noto Sans CJK KR"]:
    if font in available:
        plt.rcParams["font.family"] = font
        break
plt.rcParams["axes.unicode_minus"] = False
with (ROOT / "career_2022_2025_clean.csv").open(encoding="utf-8-sig", newline="") as f:
    rows = list(csv.DictReader(f))
years = [int(row["조사연도"]) for row in rows]
panels = [
    ("CEO_경영자_희망_퍼센트", "CEO·경영자 희망", "희망 직업이 있는 고등학생 · 가중치 미적용", "#2768B3", 6),
    ("졸업직후_창업계획_퍼센트", "고교 졸업 직후 창업 계획", "조사 응답 고등학생 전체 · 가중치 적용", "#BC6727", 6),
    ("창업_긍정관심_퍼센트", "창업에 긍정적인 관심", "관심이 있음 + 매우 관심이 있음 · 가중치 적용", "#188174", 50),
]
fig, axes = plt.subplots(1, 3, figsize=(15, 5.8))
fig.patch.set_facecolor("#FAFAF8")
for ax, (key, title, subtitle, color, ymax) in zip(axes, panels):
    values = [float(row[key]) for row in rows]
    ax.set_facecolor("#FAFAF8")
    ax.plot(years, values, color=color, marker="o", linewidth=2.7, markersize=7)
    for year, value in zip(years, values):
        ax.annotate(f"{value:.1f}%", (year, value), xytext=(0, 11), textcoords="offset points",
                    ha="center", fontsize=12, color=color, fontweight="bold")
    ax.set_title(title, fontsize=15, fontweight="bold", pad=35)
    ax.text(0.5, 1.035, subtitle, transform=ax.transAxes, ha="center", fontsize=8.7, color="#555555")
    ax.set_xticks(years)
    ax.set_xlim(2021.7, 2025.3)
    ax.set_ylim(0, ymax)
    ax.set_ylabel("응답 비율 (%)", fontsize=10)
    ax.grid(axis="y", alpha=0.22)
    ax.spines[["top", "right"]].set_visible(False)
    ax.spines[["bottom", "left"]].set_color("#AAAAAA")
fig.suptitle("대한민국 고등학생의 경영자 희망과 창업 관련 응답 | 2022–2025", x=0.06, ha="left",
             fontsize=20, fontweight="bold", y=0.97)
fig.text(0.06, 0.09, "출처: 교육부·한국직업능력연구원, 초·중등 진로교육 현황조사(2022–2025). 관심 지표의 대상은 조사 응답 고등학생 전체.", fontsize=10, color="#555555")
fig.text(0.06, 0.045, "세 지표는 질문과 응답 기준이 다릅니다. 각 그래프의 연도별 변화를 비교하세요. 세로축 범위: 왼쪽·가운데 0–6%, 오른쪽 0–50%.", fontsize=10, color="#555555")
fig.subplots_adjust(left=0.06, right=0.98, bottom=0.22, top=0.74, wspace=0.3)
fig.savefig(ROOT / "career_comparison_2022_2025.png", dpi=180, facecolor=fig.get_facecolor())
plt.close(fig)
print("career_comparison_2022_2025.png 저장 완료")
