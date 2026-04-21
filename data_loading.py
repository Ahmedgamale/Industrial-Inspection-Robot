import pandas as pd

df = pd.read_excel(
    "Merged_Sensor_Dataset.xlsx",
    sheet_name="AS7265x_Spectral_Data"
)

df.head()
print(df.info())
print(df.describe())
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier

X = df.drop("label", axis=1)
y = df["label"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

model = RandomForestClassifier()
model.fit(X_train, y_train)

print("Accuracy:", model.score(X_test, y_test))
