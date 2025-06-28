#!/bin/bash

# مسار المشروع الأساسي (لاحظ: استخدم "/" بدل "\" للهروب من مشاكل bash)
project_dir="/e/projects/F.D project"
cd "$project_dir" || { echo "❌ Failed to access project directory"; exit 1; }

# ملف تاريخ الإنشاء
created_file=".created_at"

# إنشاء التاريخ لو المشروع جديد ومفيش ملف
if [ ! -f "$created_file" ]; then
    created_date=$(date '+%Y-%m-%d_%H-%M-%S')
    echo "$created_date" > "$created_file"
    echo "🆕 Created project date: $created_date"
else
    created_date=$(cat "$created_file")
    echo "📅 Project originally created at: $created_date"
fi

# إنشاء Snapshot في مجلد خاص
snapshot_dir="/e/projects/_snapshots"
snapshot_path="$snapshot_dir/$created_date"

if [ ! -d "$snapshot_path" ]; then
    mkdir -p "$snapshot_path"
    cp -r "$project_dir" "$snapshot_path"
    echo "📁 Snapshot created at: $snapshot_path"
else
    echo "📦 Snapshot already exists at: $snapshot_path"
fi

# Git remote (optional fix if remote is wrong)
correct_remote="https://github.com/osama-mohamoud2006/Freq-distribution-.git"
git remote set-url origin "$correct_remote"

# Git pull
echo "🔄 Pulling latest changes..."
git pull origin main

# Git add & commit
git add -u
git add .

commit_msg="Auto commit: $(date '+%Y-%m-%d %H:%M:%S')"
git commit -m "$commit_msg" --quiet && echo "✅ Commit done"

# Git push
echo "🚀 Pushing to GitHub..."
git push origin main --quiet && echo "✅ Push completed"