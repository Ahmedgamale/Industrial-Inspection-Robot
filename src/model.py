import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# =============================
# Load Data
# =============================
df = pd.read_excel(
    "data/Merged_Sensor_Dataset.xlsx",
    sheet_name="AS7265x_Spectral_Data"
)

# =============================
# Features & Labels
# =============================
X = df.drop(columns=['class_label', 'dataset_type'], errors='ignore')
y = df['class_label']

# =============================
# Train / Test Split
# =============================
X_train, X_test, y_train, y_test = train_test_split(
    X, y,
    test_size=0.2,
    random_state=42,
    stratify=y  # مهم جدًا لو عندك imbalance
)

# =============================
# Scaling
# =============================
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

print("Train shape:", X_train.shape)
print("Test shape:", X_test.shape)
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report

# Model
model = RandomForestClassifier(n_estimators=100, random_state=42)

# Train
model.fit(X_train, y_train)

# Predict
y_pred = model.predict(X_test)

# Evaluation
print("Accuracy:", accuracy_score(y_test, y_pred))
print(classification_report(y_test, y_pred))

